:set number
:set relativenumber
:set autoindent
:set tabstop=4
:set shiftwidth=4
:set smarttab
:set softtabstop=4
:set mouse=a

call plug#begin(stdpath('config') . '/plugged')

Plug 'https://github.com/neoclide/coc.nvim'
Plug 'http://github.com/tpope/vim-surround'
Plug 'https://github.com/preservim/nerdtree'
Plug 'https://github.com/tpope/vim-commentary'
Plug 'https://github.com/vim-airline/vim-airline'
Plug 'https://github.com/ap/vim-css-color'
Plug 'https://github.com/rafi/awesome-vim-colorschemes'
Plug 'https://github.com/terryma/vim-multiple-cursors'
Plug 'https://github.com/preservim/tagbar'
Plug 'https://github.com/alvan/vim-closetag'
Plug 'https://github.com/ryanoasis/vim-devicons'

set encoding=UTF-8
call plug#end()

nnoremap <C-b> :NERDTreeToggle<CR>
nmap <C-i> :TagbarToggle<CR>
inoremap <expr> <Tab> pumvisible() ? coc#_select_confirm() : "<Tab>"

:set completeopt-=preview
:colorscheme molokai
