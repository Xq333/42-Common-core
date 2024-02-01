FROM debian:latest

RUN apt update && apt upgrade -y && \
  apt install -y gpg jq wget unzip lsb-release && \
  wget -O- https://apt.releases.hashicorp.com/gpg | gpg --dearmor -o /usr/share/keyrings/hashicorp-archive-keyring.gpg && \
  echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] https://apt.releases.hashicorp.com/ $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/hashicorp.list && \
  apt update && apt install -y vault && \
  apt clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY ./token-script.sh /token-script.sh
COPY ./config.hcl /config.hcl
COPY ./script1.sh /
COPY ./script2.sh /
COPY ./script3.sh /
COPY ./application-policy-DEV.hcl /application-policy-DEV.hcl

RUN chmod +x /token-script.sh

CMD ["/bin/bash", "/token-script.sh"]











# FROM debian:latest
#
# RUN apt update && apt upgrade && apt install gpg wget unzip lsb-release -y
#
# RUN wget -O- https://apt.releases.hashicorp.com/gpg | gpg --dearmor -o /usr/share/keyrings/hashicorp-archive-keyring.gpg 
#
# RUN echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] https://apt.releases.hashicorp.com/ $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/hashicorp.list
#
# RUN apt update && apt install vault -y
#
# COPY ./token-script.sh /token-script.sh
# COPY ./config.hcl /config.hcl
# COPY ./application-policy-DEV.hcl /application-policy-DEV.hcl
#
# CMD ["vault", "server", "-config=/config.hcl"]
