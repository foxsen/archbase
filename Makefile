all:
	Rscript -e 'bookdown::render_book()'

pdf:
	Rscript -e 'bookdown::render_book("index.Rmd", "bookdown::pdf_book")'

doc:
	Rscript -e 'bookdown::render_book("index.Rmd", "bookdown::word_document2")'

serve:
	Rscript -e 'bookdown::serve_book()'

clean:
	rm -rf _book _bookdown_files
