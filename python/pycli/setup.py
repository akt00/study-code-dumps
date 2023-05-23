from setuptools import setup


setup(
  name = 'py-cli',
  version = '0.1.0',
  packages=['pycli'],
  entry_points={'console_scripts': ['py-cli=pycli.main:main']},
  install_requires=['pyyaml']
)
