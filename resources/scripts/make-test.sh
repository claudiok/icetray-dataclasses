#!/bin/sh
if [ $# -ne 1 ]; then
	echo "Usage: make-test.sh <name of class to test>"
	exit 1
fi

export CLASSNAME=$1
export TESTTEMPLATE=../../resources/scripts/test-template.cxx
export TESTSOURCE=${CLASSNAME}Test.cxx

if [ -e $TESTSOURCE ]; then
	echo $TESTSOURCE" exists already.  I won't overwrite it"
	exit 1
fi

cat $TESTTEMPLATE | sed s/__TESTED_CLASS__/$CLASSNAME/g > $TESTSOURCE
