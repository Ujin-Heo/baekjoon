#!/bin/bash

# This script finds all C files (.c extension) within subdirectories
# of the current directory and replaces spaces in their filenames with underscores.

echo "Starting filename sanitation for C files..."

# Find all directories in the current directory.
# The -maxdepth 1 option ensures only direct subdirectories are considered.
# The -type d option filters for directories.
# The -print0 option prints the full file name on the standard output, followed by a null character.
# This helps in handling filenames with spaces or special characters safely.
find . -maxdepth 1 -type d -print0 | while IFS= read -r -d $'\0' dir; do
    # Skip the current directory itself, if it's found (represented as ".")
    if [[ "$dir" == "." ]]; then
        continue
    fi

    echo "Processing directory: $dir"

    # Find all .c files within the current subdirectory.
    # -type f filters for regular files.
    # -name "*.c" matches files ending with .c.
    # -print0 again for safe handling of filenames.
    find "$dir" -type f -name "*.c" -print0 | while IFS= read -r -d $'\0' file; do
        # Construct the new filename by replacing all spaces with underscores.
        # Basename extracts the filename from the full path.
        # The `sed` command performs the replacement:
        # 's/ /_/g' means substitute (s) a space character ( ) with an underscore (_) globally (g).
        filename=$(basename "$file")
        new_filename=$(echo "$filename" | sed 's/ /_/g')

        # Construct the full new path for the file.
        # dirname extracts the directory path from the full file path.
        new_file_path=$(dirname "$file")/"$new_filename"

        # Check if the filename actually changed.
        if [[ "$filename" != "$new_filename" ]]; then
            # If changed, rename the file.
            echo "Renaming '$file' to '$new_file_path'"
            mv "$file" "$new_file_path"
        else
            echo "No spaces found in '$file', skipping."
        fi
    done
done

echo "Filename sanitation complete."
