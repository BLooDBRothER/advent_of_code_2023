#!/bin/bash

if [ $# -eq 0 ]
then
    echo "Please enter the day no"
    exit 1
fi

dayNo=$1

folderName="day$1"
fileName="day$1"
filePath="$folderName/$fileName"

cppFileName="day$1.cpp"
cppfilePath="$folderName/$cppFileName"

outputFolder="./bin/$folderName"
exeOutputFilePath="$outputFolder/$fileName"

if [[ ! -d "$folderName" ]]
then
    echo "$folderName directory does not exists on your filesystem."
    exit 1
fi

if [[ ! -f "$cppfilePath" ]]
then
    echo "$cppfilePath file does not exists on your filesystem."
    exit 1
fi

includeFilePath="include"

echo "Starting..."

mkdir -p $outputFolder

echo "Compiling $fileName file..."
g++ --std=c++11 -I $includeFilePath -o $exeOutputFilePath $cppfilePath

echo "Running day$1....."
$exeOutputFilePath

