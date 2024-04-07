all: upgrade install config suckless ohmyzsh

upgrade:
	echo "\n>>> Update and upgrade"
	sudo cp -fr .install/sources.list.sid /etc/apt/sources.list
	sudo cp -fr .install/sudoers /etc/sudoers
	sudo apt -qq -y update
	sudo apt -qq -y full-upgrade


install:
	echo "\n>>> Install zsh, vim and friends"
	sudo apt -qq -y install micro nnn vim zsh greetd dwm stterm xorg okular zathura suckless-tools aptitude
	sudo cp -fr .install/greetd.config.toml /etc/greetd/config.toml
	sudo apt -qq -y install 'fonts-hac*' 'fonts-libe*' eog caja dunst flameshot trash-cli
	sudo apt -qq -y install git curl wget xinit feh tmux
	sudo apt -qq -y install fonts-font-awesome fonts-terminus-otb fonts-agave
	sudo apt -qq -y install x11-utils libreadline-dev libx11-dev libxinerama-dev libxft-dev numlockx 
	sudo apt -qq -y install fzf fd-find bat tree ripgrep btop locales-all build-essential gcc rsstail slock trash-cli moc
	sudo apt -qq -y autoremove
	sudo aptitude -y -q=5 autoclean
	sudo aptitude -y -q=5 purge

ohmyzsh:
	echo "\n>>> Install Oh-my-zsh"
	sudo apt -qq -y install zsh
	rm -fr "/home/cedric/.oh-my-zsh" 2> /dev/null
	wget -q "https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh"
	chmod +x ./install.sh
	./install.sh --unattended
	rm -fr ./install.sh
	git clone https://github.com/zsh-users/zsh-autosuggestions ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
	git clone https://github.com/zsh-users/zsh-syntax-highlighting ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
	cp -fr .zshrc ~/
	echo "\n>>> Change Shell to zsh"
	chsh -s /bin/zsh

config:
	echo "\n>>> Copy .zshrc, .vimrc and friends to ~/"
	cp -fr .w ~/
	cp -fr .dwm ~/
	cp -fr .vimrc ~/
	cp -fr .moc ~/
	cp -fr .xinitrc ~/
	cp -fr .Xresources ~/
	cp -fr .latexmkrc ~/
	cp -fr .config ~/
	sudo cp -fr bin/* /usr/bin/
	cp -fr .fonts ~/
	fc-cache -r

suckless:
	echo "\n>>> Install dwm, st and friends"
	sudo make -C dev clean install --silent

packages:
	echo "\n>>> Install some packages"
	sudo apt -qq -y install gimp firefox firefox-l10n-fr texlive-full chromium chromium-l10n evince okular pdftk imagemagick


.SILENT:
