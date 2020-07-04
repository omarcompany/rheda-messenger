#!  /bin/bash

sudo apt-get install -y build-essential dpkg debconf debhelper lintian
sudo apt-get install -y fakeroot
sudo apt-get install -y devscripts python-pip python3-pip python3-setuptools
sudo pip3 install -U pip
sudo pip3 install gbp

#make distclean

export DEBEMAIL="alekseytatarv@gmail.com"
export DEBFULLNAME="Aleksey Tatarov"

sudo gbp dch --since 0.0.1 --ignore-branch
TAG=$(git describe --tags $(git rev-list --tags --max-count=1))
sed -i "s/.*(VERSION).*/rheda-messenger (${TAG}) UNRELEASED; urgency=medium/" debian/changelog

cat debian/changelog

dpkg-buildpackage -us -uc
