#!/bin/bash

sleep 3

conf_file="/var/www/html/wp-config.php"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

download_wordpress()
{
     echo -e "${YELLOW}Attempting to download WordPress...${NC}"
    if wp core download --allow-root; 
    then
        echo -e "${GREEN}Download successful.${NC}"
        return 1
    else
        echo -e "${RED}Download failed.${NC}"
        return 0
    fi
}

configuration_wordpress() 
{
    echo -e "${YELLOW}Configuring WordPress...${NC}"
    if wp config create \
        --allow-root \
        --path=/var/www/html/ \
        --dbname=$DB_NAME \
        --dbuser=$DB_ADMIN_USER \
        --dbpass=$DB_ADMIN_PASS \
        --dbhost=$DB_HOST
    then
        echo -e "${GREEN}Configuration successful.${NC}"
        return 1
    else
        echo -e "${RED}Configuration failed.${NC}"
        return 0
    fi
}

install_wordpress()
{
    echo -e "${YELLOW}Installing WordPress...${NC}"
    if wp core install    \
        --allow-root \
        --title=$WP_TITLE \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIM_PASS \
        --admin_email=$WP_ADMIM_EMAIL \
        --url=$DOMAIN
    then
        wp user create \
        --allow-root \
        $WP_USER $WP_USER_EMAIL \
        --user_pass=$WP_USER_PASS
        return 1
    else
        return 0
    fi
}

if [ ! -e "$conf_file" ]; then

    command=0
    attempts=0
    max_attempts=5
    
    cd /var/www/html/

    while [ $attempts -le $max_attempts ]; do

        if [ $command -eq 0 ]; then
            download_wordpress
            ((command+=$?))
        fi
        if [ $command -eq 1 ]; then
            configuration_wordpress
            ((command+=$?))
        fi
        if [ $command -eq 2 ]; then
            install_wordpress
            ((command+=$?))
        fi
        if [ $command -ge 3 ]; then
            break
        fi
        ((attempts+=1))

        sleep 1

    done
    
    if [ $attempts -ge $max_attempts ]; then
        echo "Failed to install WordPress."
    else
        echo "WordPress installation successfully."
    fi
  
else
    echo "Wordpress already installed and ready to use."
fi

exec "$@"


