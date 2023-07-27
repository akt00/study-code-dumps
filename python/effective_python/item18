# defaultdict vs __missing__

from collections import defaultdict
import sys


def open_picture(profile_path):
    try:
        return open(profile_path, 'r')
    except OSError:
        print(f'failed to open path {profile_path}', sys.stderr)
        raise


class Picture(dict):
    def __missing__(self, key):
        value = open_picture(key)
        self[key] = value
        return value


pic = Picture()
handle = pic['test.py']
handle.seek(0)
data = handle.read()
