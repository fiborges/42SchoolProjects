# Containers Names
MARIADB		= mariadb
NGINX		= nginx
WORDPRESS	= wordpress

# Docker Compose
COMPOSE		= sudo docker compose -f srcs/docker-compose.yml
DOCKER		= sudo docker

include srcs/.env

# Define Colors
YELLOW	= \033[0;33m
CYAN	= \033[0;36m
NC		= \033[0m

# Targets
.SILENT:

# --- Main Targets ---
all: mkdir-data compose-build compose-up
	@echo "${CYAN}>>> All services started successfully! <<<${NC}"

start: compose-up
	@echo "${CYAN}>>> Services started successfully! <<<${NC}"

stop: compose-stop
	@echo "${CYAN}>>> Services stopped successfully! <<<${NC}"

clean: compose-clean
	@echo "${CYAN}>>> All services cleaned up successfully! <<<${NC}"

clean-data: clean
	sudo rm -rf $(VOLUMES_PATH)
	@echo "${CYAN}>>> All data cleaned up successfully! <<<${NC}"

re: clean all

logs:
	$(COMPOSE) logs

info:
	@echo "${YELLOW}------------------------------------------${NC}"
	@echo "${CYAN}>>> Docker Compose Status <<<${NC}"
	@echo "${YELLOW}------------------------------------------${NC}"
	$(COMPOSE) ps -a
	@echo "${YELLOW}------------------------------------------${NC}"
	@echo "${CYAN}>>> Docker Images <<<${NC}"
	@echo "${YELLOW}------------------------------------------${NC}"
	$(DOCKER) images
	@echo "${YELLOW}------------------------------------------${NC}"
	@echo "${CYAN}>>> Docker Networks <<<${NC}"
	@echo "${YELLOW}------------------------------------------${NC}"
	$(DOCKER) network ls
	@echo "${YELLOW}------------------------------------------${NC}"
	@echo "${CYAN}>>> Docker Volumes <<<${NC}"
	@echo "${YELLOW}------------------------------------------${NC}"
	$(DOCKER) volume ls
	@echo "${YELLOW}------------------------------------------${NC}"

# --- Interactive Shells ---
maria_shell:
	$(DOCKER) exec -it mariadb_conteiner /bin/bash

nginx-shell:
	$(DOCKER) exec -it nginx_conteiner /bin/bash

wordpress-shell:
	$(DOCKER) exec -it wordpress_conteiner /bin/bash


.PHONY: all start stop clean clean-data re logs info mariadb-it nginx-it wordpress-it

mkdir-data:
	sudo mkdir -p $(VOLUMES_PATH)/data/mysql $(VOLUMES_PATH)/data/wordpress

compose-build:
	$(COMPOSE) build --no-cache

compose-up:
	$(COMPOSE) up -d

compose-stop:
	$(COMPOSE) stop

compose-clean:
	$(COMPOSE) down --rmi all --volumes