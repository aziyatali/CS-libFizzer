Sample Bug Report
Name:
Segmentation Fault

Description
in pngparser.c(line:1116)
  FILE *output = fopen(filename, "wb");

When filename cannot be opened and output is NULL, then store_png_rgb_alpha(output, img); tries
to store NULL output and it gives an error message.


Affected Lines
In pngparcer.c: 1116
Expected vs Observed:
We need to handle the case when   FILE *output = fopen(filename, "wb"); and output is NULL.
Steps to Reproduce
Command
./fuzer_store_png_rgba crash-4dd8f91f3a6d6df6b6db6f9ce342cf6d177e3191

Proof-of-Concept Input (if needed)
(attached: poc.png and log file)

Suggested Fix Description
We need to check the "output" is NULL or not. If it is NULL then store it otherwise give error message.
