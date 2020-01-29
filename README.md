# fastqc-summary
Summarize fastqc results by parsing the fastqc_data.txt files output by a fastqc run.


### Installation

Clone this repository, `cd` into fastqc-summary and type `make` or `make clean`

### Usage Information
`fastqc-summary -f FASTQC_OUT_DIRECTORY/`

The `FASTQC_OUT_DIRECTORY/` is the output directory containing the .html and .zip files from a fastqc run. Decompress the zipped files and pass the `FASTQC_OUT_DIRECTORY/` to `fastqc-summary`. The resulting output is a matrix containing pass/warn/fail status of each fastqc module in .csv format for each fastq file passed in the original fastqc run.


Currently tested for fastqc version 0.11.7 and newer.
Link to fastqc: http://www.bioinformatics.babraham.ac.uk/projects/fastqc/


