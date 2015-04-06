#!/bin/bash
# Add exercise
# Generate a new CLion project for a USACO exercise

if [ $# -ne 2 ] 
then
  echo "Syntax: $0 <project name> <parent directory>"
  exit 1
fi

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
PROJECT_NAME=$1
PARENT_DIR=$2
TARGET_DIR=`readlink -f $2/$1/`

if [ ! -d $PARENT_DIR ]; then
  echo Directory $PARENT_DIR does not exist.
  exit 1
fi

cp -rp $DIR/template $TARGET_DIR
cd $TARGET_DIR
mv .idea/template.iml .idea/$PROJECT_NAME.iml
mv template.cpp $PROJECT_NAME.cpp
touch $PROJECT_NAME.in
find $TARGET_DIR -type f -exec sed -i "s/%PROJECT_NAME%/$PROJECT_NAME/g" {} \;
