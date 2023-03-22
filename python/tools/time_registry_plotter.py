import os
import re
import json
import traceback

import numpy as np
from typing import List, Dict
from matplotlib import pyplot


def parse_log_file(log_filename: str) -> Dict[str, List[float]]:
    log_file = open(log_filename, 'r')

    time_results = json.load(log_file)
    log_file.close()
    return time_results


def is_outlier(data: List[float]):
    points = np.array(data)

    if len(points.shape) == 1:
        points = points[:, None]
    median = np.median(points, axis=0)
    diff = np.sum((points - median) ** 2, axis=-1)
    diff = np.sqrt(diff)
    med_abs_deviation = np.median(diff)

    modified_z_score = 0.6745 * diff / med_abs_deviation

    return modified_z_score > 3.5


def plot(name: str, time_results: Dict[str, List[float]], filter_outliers: bool) -> None:
    pyplot.figure(figsize=(8, 6))
    for label in time_results:
        data = time_results[label]
        outlier_mask = is_outlier(data=data)
        if filter_outliers:
            data = [datapoint for (datapoint, mask) in zip(data, outlier_mask) if not mask]
        pyplot.hist(data, bins=50, alpha=0.8, label=label)
    pyplot.xlabel('Time [ms]')
    pyplot.ylabel('Count')
    pyplot.legend(loc='upper right')

    pyplot.savefig(os.getcwd() + '/graphs/' + name + '_graph.png')


def get_filename_no_extension(filename: str) -> str:
    base_name = os.path.basename(filename)
    return os.path.splitext(base_name)[0]


class FilenameException(Exception):
    pass


def validate_filename(filename: str) -> None:
    json_filename_pattern = re.compile(r'^(/([A-Z]|[a-z]|[-_.])+)+(.json)$')
    result = json_filename_pattern.fullmatch(filename)
    if result is None:
        raise FilenameException('Provided input_file argument is not a valid .json file path.')


def main(filename: str, filter_outliers: bool):
    try:
        validate_filename(filename)
    except FilenameException:
        traceback.print_exc()
        return

    time_results = parse_log_file(filename)
    plot(get_filename_no_extension(filename), time_results, filter_outliers)


if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description='Plot your time registry outputs')
    parser.add_argument('input_file', metavar='input-file', action='store', type=str,
                        help='Path of the .json log file generated using TimeRegistry.')
    parser.add_argument('-fo', '--filter-outliers', action='store_true',
                        help='Filter outliers from provided data.')
    args = parser.parse_args()
    main(args.input_file, args.filter_outliers)
