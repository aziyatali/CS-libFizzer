Sample Bug Report
Name:
Segmentation Fault

Description
in pngparser.c(line:556)
  FILE *input = fopen(filename, "rb");
When file cannot be opened and input is NULL, it gives an error message.
Then error message directly closes the input file. Which means input is useless because we don't assign the return value to a file pointer. That means the "filename" file will be opened for writing, but we will never be able to write anything in it

Affected Lines
In pngparcer.c: 704
Expected vs Observed:
I don't see a reason to call fclose here since if fopen returns NULL, there isn't anything to close.
That is probably the reason for seg fault. We are trying to close a null pointer

Steps to Reproduce
Command
./fuzer_load_png_name crash-da39a3ee5e6b4b0d3255bfef95601890afd80709

Proof-of-Concept Input (if needed)
(attached: poc.png and log file)

Suggested Fix Description
We need to check the "filename" and if it is NULL then just return the error message not close it with fclose. 
