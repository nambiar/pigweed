# Copyright 2019 The Pigweed Authors
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
"""pw_unit_test"""

import unittest
import setuptools


def test_suite():
    """Test suite for pw_unit_test module."""
    return unittest.TestLoader().discover('./', pattern='*_test.py')


setuptools.setup(
    name='pw_unit_test',
    version='0.1.0',
    author='Pigweed Authors',
    author_email='pigweed-developers@googlegroups.com',
    description='Unit tests for Pigweed projects',
    packages=setuptools.find_packages(),
    test_suite='setup.test_suite',
    install_requires=[
        'pw_cli',
    ],
)
