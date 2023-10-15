all:
	echo "\n>>> Update and upgrade"
	sudo apt -qq -y update
	sudo apt -qq -y full-upgrade

	echo "\n>>> Install zsh, vim and friends"
	sudo apt -qq -y install zsh vim curl wget xorg micro nnn greetd xinit feh
	sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
	git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
	git clone https://github.com/zsh-users/zsh-syntax-highlighting ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
	
	echo "\n>>> Copy .zshrc, .vimrc and friends to ~/"
	cp -fr .w ~/
	cp -fr .fonts ~/
	fc-cache -r
	cp -fr .vimrc ~/
	cp -fr .zshrc ~/

	echo "\n>>> Install dwm, st and friends"
	sudo make -C dev clean install --silent
	 
.SILENT:
