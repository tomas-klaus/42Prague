#!/bin/bash

# Path to the executable
EXECUTABLE="./so_long"

# Path to the maps_err directory
MAPS_DIR="./maps_valid"

# Loop through all files in the maps_err directory
for map in "$MAPS_DIR"/*
do
  # Run the executable with the current map
  echo "
  Running map $map"
  $EXECUTABLE "$map"
done