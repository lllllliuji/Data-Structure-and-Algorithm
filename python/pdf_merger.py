from pypdf import PdfWriter
import os

# Specify the directory path you want to traverse
directory_path = r'C:\Users\liuji\Desktop\cs162-pku\pdf'

file_paths = []

# Iterate through all files in the directory
for filename in os.listdir(directory_path):
    # Get the full path of the file
    file_path = os.path.join(directory_path, filename)
    
    # Check if it's a file (not a subdirectory)
    if os.path.isfile(file_path):
        file_paths.append(file_path)

# Sort the file paths based on their names
file_paths.sort()

merger = PdfWriter()

for pdf in file_paths:
    merger.append(pdf)

# Specify the output path in the same directory
output_path = os.path.join(directory_path, "merged-pdf.pdf")

merger.write(output_path)
merger.close()
