all:
	r -e 'bookdown::render_book()'

pdf:
	r -e 'bookdown::render_book("index.Rmd", "bookdown::pdf_book")'

doc:
	r -e 'bookdown::render_book("index.Rmd", "bookdown::word_document2")'

serve:
	r -e 'bookdown::serve_book()'

clean:
	rm -rf _book _bookdown_files
