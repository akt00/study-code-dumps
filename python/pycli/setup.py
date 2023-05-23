from setuptools import setup

# pypi package name can contain chars such as '-'
# library name must only consits of lower alnum chars
setup(
  name='py-cli',
  version='0.1.0',
  packages=['pycli'],
  entry_points={'console_scripts': ['py-cli=pycli.main:main']},
  install_requires=['pyyaml']
)
