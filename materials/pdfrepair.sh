#!/usr/bin/bash

#repair the pdf file
/usr/bin/gs \
  -o gs-repaired---$1 \
  -dPDFSETTINGS=/prepress \
  -sDEVICE=pdfwrite \
   $1 
