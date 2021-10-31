from ubuntu:20.04

# select faster mirror
RUN sed -i -e 's/archive.ubuntu.com/mirrors.tuna.tsinghua.edu.cn/' /etc/apt/sources.list

RUN DEBIAN_FRONTEND=noninteractive apt-get update

# install necessary packages
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y git r-base-core vim

# they are needed to build r packages via renv::restore()
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libxml2-dev \
    libfontconfig1-dev libfreetype-dev libcairo2-dev
RUN Rscript -e "install.packages('renv')"

# use renv to recover r environment
RUN cd /opt && git clone --depth 1 https://github.com/foxsen/archbase && cd archbase
RUN cd /opt/archbase && Rscript -e "renv::restore()"

# install tinytex environment for make pdf
RUN Rscript -e "renv::install('tinytex')"
RUN Rscript -e "tinytex::install_tinytex()"

# install Chinese fonts, flextable need used fonts to calculate table width
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y fonts-noto-cjk

# set Chinese locale
RUN apt-get install -y locales
RUN sed -i -e 's/# zh_CN.UTF-8 UTF-8/zh_CN.UTF-8 UTF-8/' /etc/locale.gen && \
    locale-gen
ENV LC_ALL zh_CN.UTF-8

# install pandoc 2.11
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y wget
RUN wget -c https://github.com/jgm/pandoc/releases/download/2.11.4/pandoc-2.11.4-1-amd64.deb && \
    dpkg -i ./pandoc-2.11.4-1-amd64.deb && \
    rm -f ./pandoc-2.11.4-1-amd64.deb

RUN export PATH=$PATH:/root/bin && cd /opt/archbase && make pdf

WORKDIR /opt/archbase
ENV PATH="$PATH:/root/bin"
