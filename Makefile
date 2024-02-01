all:
	echo "\n>>> Update and upgrade"
	sudo apt -qq -y update
	sudo apt -qq -y full-upgrade

	echo "\n>>> Install zsh, vim and friends"
	sudo apt -qq -y install zsh vim curl wget xorg micro nnn greetd xinit feh tmux fonts-hack fonts-hack-otf fonts-hack-ttf fonts-hack-web fonts-font-awesome fonts-terminus-otb x11-utils libreadline-dev libx11-dev libxinerama-dev libxft-dev numlockx fzf fd-find bat tree ripgrep btop locales-all build-essential gcc rsstail fonts-agave slock trash-cli
	wget "https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh"
	chmod +x ./install.sh
	./install.sh --unattended
	rm -fr ./install.sh
	git clone https://github.com/zsh-users/zsh-autosuggestions ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
	git clone https://github.com/zsh-users/zsh-syntax-highlighting ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
	
	echo "\n>>> Copy .zshrc, .vimrc and friends to ~/"
	cp -fr .w ~/
	cp -fr .dwm ~/
	cp -fr .fonts ~/
	fc-cache -r
	cp -fr .vimrc ~/
	cp -fr .moc ~/
	cp -fr .zshrc ~/
	cp -fr .xinitrc ~/
	cp -fr .Xresources ~/
	cp -fr .latexmkrc ~/
	sudo cp -fr hdmi /usr/bin/
	

	echo "\n>>> Install dwm, st and friends"
	sudo make -C dev clean install --silent

	echo "\n>>> Change Shell to zsh"
	chsh -s /bin/zsh

.SILENT:
