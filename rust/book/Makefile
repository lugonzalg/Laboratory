COMPOSE=docker compose -f ./docker-compose.yml

.PHONY: all build clean fclean live re

all:
	$(COMPOSE) up -d

live:
	$(COMPOSE) up

build:
	$(COMPOSE) build $(ARGS)

in:
	$(COMPOSE) exec book sh

down:
	$(COMPOSE) down

ps:
	$(COMPOSE) ps