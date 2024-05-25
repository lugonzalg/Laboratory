FROM rust:alpine3.20

ARG USER

RUN apk add vim git \
    && adduser -D -s /bin/bash $USER

USER $USER

RUN git config --global user.name "lugonzalg" \
    && git config --global user.email "luxample@example.com"


WORKDIR /app