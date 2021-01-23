FROM	debian:buster 

LABEL	maintainer="taekang@student.42seoul.kr"

RUN	apt-get update && apt-get install -y \
	nginx \
	mariadb-server \
	php-mysql \
	openssl \
	vim \
	wget \
	php7.3-fpm

COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp
COPY	./srcs/run.sh ./

EXPOSE	80 443

CMD 	bash run.sh
