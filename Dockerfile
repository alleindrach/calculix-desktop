# Builds a Docker image for Multithreaded version of CalculiX
#
# Authors:
# Alleindrach<alleindrach@gmail.com>

FROM x11vnc/desktop:latest
LABEL maintainer "AlleinDrach<alleindrach@gmail.com>"

USER root
WORKDIR /tmp
ADD image/usr /usr

# Install system packages


RUN sh -c "curl -s http://dl.openfoam.org/gpg.key | apt-key add -" && \
    add-apt-repository http://dl.openfoam.org/ubuntu && \
    apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        gcc \
        gfortran \
        git \
        xorg-dev  \ 
        libglu1-mesa-dev \
        python3-pip \
        paraviewopenfoam56  \
        tetgen \
        imagemagick \
        gnuplot-x11 && \
    apt-get clean && \
    apt-get autoremove && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN pip3 install --upgrade gmsh

COPY ccx_prool ./ccx
# Checkout CalcluiX_MT and compile it with Spooles and OpenMP
RUN cd ccx && \
    CALCULIX_HOME=$PWD make  && \
    ln  -s $PWD/ccx /usr/local/bin/ccx

COPY cgx_prool ./cgx
RUN cd cgx/cgx_2.19/src && \
    make  && \
    ln -s $PWD/cgx /usr/local/bin/cgx 




########################################################
# Customization for user
########################################################
RUN echo "export OMP_NUM_THREADS=\$(nproc)" >> $DOCKER_HOME/.profile && \
    chown -R $DOCKER_USER:$DOCKER_GROUP $DOCKER_HOME

WORKDIR $DOCKER_HOME
