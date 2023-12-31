cmd_/home/aransmith/linux/vsmod/main.mod := printf '%s\n'   main.o | awk '!x[$$0]++ { print("/home/aransmith/linux/vsmod/"$$0) }' > /home/aransmith/linux/vsmod/main.mod
