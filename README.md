# fastqc-summary
Creates a .csv summary of fastqc results by parsing the fastqc_data.txt files output by a fastqc run.

### Installation

clone this repository, `cd` into fastqc-summary and type `make` or `make clean`

### Usage Information
`fastqc-summary -f FASTQC_OUT_DIRECTORY/`

Unzip the zipped directories containing the fastqc_data.txt files in the output directory created by a fastqc run and pass the output directory to `fastqc-summary`. The resulting output is the pass/warn/fail status of each fastqc module in csv format for each fastq file passed in the original fastqc run.


