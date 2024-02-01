FROM python:3.8.10

ENV PYTHONUNBUFFERED 1

COPY requirements.txt /

COPY wait-for-db.sh /wait-for-db.sh

RUN chmod +x /wait-for-db.sh

RUN pip install --upgrade pip

RUN pip install -r requirements.txt

RUN apt-get update && apt-get install -y postgresql-client
WORKDIR /code
COPY . /code
