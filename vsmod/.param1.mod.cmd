cmd_/home/aransmith/linux/vsmod/param1.mod := printf '%s\n'   param1.o | awk '!x[$$0]++ { print("/home/aransmith/linux/vsmod/"$$0) }' > /home/aransmith/linux/vsmod/param1.mod
