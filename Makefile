NAME=notebook

view: $(NAME).pdf
	evince $(NAME).pdf &

$(NAME).pdf: $(NAME).tex src/*.cpp
	pdflatex $(NAME).tex

.PHONY: clean

clean:
	rm -rf $(NAME).log $(NAME).aux $(NAME).toc $(NAME).dvi
