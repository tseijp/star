#!/bin/bash
# Exit on error
set -e

# Where will the output go?
if [ "$(git rev-parse --is-inside-work-tree)" = "true" ];
then GIT_PATH=`git rev-parse --show-toplevel`
else GIT_PATH="$(pwd)/star/"
fi

# download using git and wget
if [ -d $GIT_PATH ];
then echo "${GIT_PATH} already exists so skipping"
else
  GITHUB_PREFIX="https://github.com/tseijp/"
  GITHUB_SUFFIX=".git"
  GITHUB_LINK="${GITHUB_PREFIX}star${GITHUB_SUFFIX}"
  echo "Cloning from ${GITHUB_LINK}"
  git clone $GITHUB_LINK
fi

# Each Google Drive Link
GDRIVE_PREFIX="https://drive.google.com/"
GDRIVE_QUERY="uc?export=download&id="
GDRIVE_CPPID="1TDlQFc2UFsoWns5RAJVuoDMv84Gs-W4g"
GDRIVE_PPMID="1Jdfbp7dfuSp5lHZQbzEoJjeErrK4g7pv"
CPP_LINK="${GDRIVE_PREFIX}${GDRIVE_QUERY}${GDRIVE_CPPID}"
PPM_LINK="${GDRIVE_PREFIX}${GDRIVE_QUERY}${GDRIVE_PPMID}"
CPP_PATH="${GIT_PATH}src/animateall.cpp"
PPM_PATH="${GIT_PATH}src/tmp/world.ppm"

# if animateall.cpp file is exist or not
if [ -f $CPP_PATH ];
then echo "${CPP_PATH} already exists so skipping"
else wget "${CPP_LINK}" -O "${CPP_PATH}" -x -N
fi

# if world.ppm file is exist or not
if [ -f $PPM_PATH ];
then echo "${PPM_PATH} already exists so skipping"
else wget "${PPM_LINK}" -O "${PPM_PATH}" -x -N
fi