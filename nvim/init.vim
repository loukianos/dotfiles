"Luke's vimrc

"Plugins
call plug#begin('~/.config/nvim/plugged')
" Basics
Plug 'autozimu/LanguageClient-neovim', {
\ 'branch': 'next',
\ 'do': 'bash install.sh',
\ }
Plug 'Shougo/deoplete.nvim', {'do': ':UpdateRemotePlugins'}
Plug 'scrooloose/nerdtree'
Plug 'scrooloose/syntastic'
Plug 'jiangmiao/auto-pairs'
Plug 'tomtom/tcomment_vim'
Plug 'tpope/vim-surround'
Plug 'bling/vim-airline'
Plug 'neomake/neomake', { 'for': ['rust'] }
Plug 'airblade/vim-rooter'
Plug 'junegunn/fzf', { 'dir': '~/.local/src/fzf', 'do': './install --all' }
Plug 'junegunn/fzf.vim'
Plug 'w0rp/ale'

" Git helpers
Plug 'airblade/vim-gitgutter'
Plug 'tpope/vim-fugitive'
Plug 'Xuyuanp/nerdtree-git-plugin'

"Color & syntax
Plug 'mhartington/oceanic-next'
Plug 'Yggdroot/indentLine'

"Language Specific
" Rust
Plug 'rust-lang/rust.vim', {'for': 'rust'}
Plug 'racer-rust/vim-racer', { 'for': 'rust' }
" Python
Plug 'zchee/deoplete-jedi'
call plug#end()


" Basic Settings
" colors
syntax on
colorscheme OceanicNext
" filetype-specific plugins and indentation
filetype plugin indent on
" relative numbers around an absolute number
set number
set relativenumber
" incremental, smart-cased, no-highlight search
set incsearch
set ignorecase
set smartcase
set nohlsearch
" tab completion
set wildmenu
set wildmode=longest:list,full
" no wrapping long lines
set nowrap
" show line and column number
set ruler
" replace tabs with spaces -- TODO: this ought to be language-specific if possible,
" or at least disabled for .tsv
set expandtab
" scroll a bit at the end of a line
set sidescroll=6
"open splits to the right and below rather than to the left and above
set splitright
set splitbelow
"show matching bracket
set showmatch
"comment enter
setlocal formatoptions=croql

"LanguageClient integration"

let g:LanguageClient_serverCommands = {
    \ 'rust': ['~/.cargo/bin/rustup', 'run', 'nightly', 'rls'],
    \ 'javascript': ['/usr/local/bin/javascript-typescript-stdio'],
    \ 'javascript.jsx': ['tcp://127.0.0.1:2089'],
    \ 'python': ['/usr/local/bin/pyls'],
    \ }

" Language specific
" Rust
let g:rustfmt_autosave = 1
let g:racer_cmd = "/home/loukianos/.cargo/bin/racer"
let g:racer_experimental_completer = 1

au FileType rust nmap gd <Plug>(rust-def)
au FileType rust nmap gs <Plug>(rust-def-split)
au FileType rust nmap gx <Plug>(rust-def-vertical)
au FileType rust nmap <leader>gd <Plug>(rust-doc)

" "Keymap
" set leader and remap colon to space
let mapleader=";"
nnoremap <SPACE> :

" shortcut to edit this init.vim file
nnoremap <silent> <leader>ec :e $MYVIMRC<CR>
" shortcut to source this config file after editing it
nnoremap <silent> <leader>ecs :source $MYVIMRC<CR>

" use ;; and fd for escape
inoremap fd <Esc>
inoremap ;; <Esc>

" clear searches easily
nnoremap <leader>xs :nohlsearch<CR>

" toggle NERDtree
nnoremap <silent> <leader>nt :NERDTreeToggle<CR>

"fzf hotkey"
nnoremap <silent> <leader>ff :FZF<CR>

" toggle buffer
nnoremap <silent> <leader>bb <C-^>

" go to next or previous buffer
nnoremap <silent> <leader>bn :bn<CR>
nnoremap <silent> <leader>bp :bp<CR>

" close or kill buffer
nnoremap <silent> <leader>bd :bd<CR>
nnoremap <silent> <leader>bk :bk<CR>

" list buffers
nnoremap <silent> <leader>bl :ls<CR>

" list buffers and navigate
nnoremap <silent> <leader>bg :ls<CR>:buffer<Space>

" horizontal or vertical split with new buffer
nnoremap <silent> <leader>bh :new<CR>
nnoremap <silent> <leader>bv :vnew<CR>

" improved keyboard navigation
nnoremap <leader>h <C-w>h
nnoremap <leader>j <C-w>j
nnoremap <leader>k <C-w>k
nnoremap <leader>l <C-w>l
nnoremap <leader>a <C-w>+
nnoremap <leader>s <C-w>-

" improved keyboard support for navigation (especially terminal)
" https://neovim.io/doc/user/nvim_terminal_emulator.html
tnoremap <Esc> <C-\><C-n>
tnoremap <leader><leader> <C-\><C-n>
tnoremap fd <C-\><C-n>
tnoremap <A-h> <C-\><C-n><C-w>h
tnoremap <A-j> <C-\><C-n><C-w>j
tnoremap <A-k> <C-\><C-n><C-w>k
tnoremap <A-l> <C-\><C-n><C-w>l
nnoremap <A-h> <C-w>h
nnoremap <A-j> <C-w>j
nnoremap <A-k> <C-w>k
nnoremap <A-l> <C-w>l


" Start terminal in insert mode
au BufEnter * if &buftype == 'terminal' | :startinsert | endif
nnoremap <silent> <leader>tt :terminal<CR>
nnoremap <silent> <leader>tv :vnew<CR>:terminal<CR>
nnoremap <silent> <leader>th :new<CR>:terminal<CR>
tnoremap <C-x> <C-\><C-n><C-w>q

" http://vim.wikia.com/wiki/Highlight_current_line
" http://stackoverflow.com/questions/8750792/vim-highlight-the-whole-current-line
" http://vimdoc.sourceforge.net/htmldoc/autocmd.html#autocmd-events
autocmd BufEnter * setlocal cursorline
autocmd WinEnter * setlocal cursorline
autocmd BufLeave * setlocal nocursorline
autocmd WinLeave * setlocal nocursorline




"Auto-completion settings
let g:deoplete#enable_at_startup = 1
