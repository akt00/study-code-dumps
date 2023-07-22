import pytest
from unittest.mock import patch

import funcs


@pytest.fixture(scope='session')
def set_up():
    print('fixture being set up')
    return None


def test_1(set_up):
    res = set_up
    assert res is None


def test_2(set_up):
    res = set_up
    assert res is None


def test_mock():
    with patch.object(target=funcs, attribute='sleep', return_value=None) as mock:
        res = funcs.sleep(10)
        mock.assert_called_once_with(10)
        assert res is None
