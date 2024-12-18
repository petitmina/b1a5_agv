from setuptools import setup
from glob import glob
import os 

package_name = 'agv'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='er',
    maintainer_email='ying.zhang@elephantrobotics.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'pub = agv.pub:main',
            'sub = agv.sub:main',
            'tel = agv.tel:main',
            'udp = agv.udp:main',
            'pub2 = agv.pub2:main',
            'sub2 = agv.sub2:main',
            'return = agv.return_sub:main',
            'pub4 = agv.pub4:main'
        ],
    },
)
