vim.g.mapleader = ' '
vim.g.maplocalleader = ' '

local map = vim.keymap.set

-- Window navigation
map('n', '<leader>wn', '<C-w><C-h>', { desc = 'Move to left window' })
map('n', '<leader>we', '<C-w><C-j>', { desc = 'Move to lower window' })
map('n', '<leader>wi', '<C-w><C-k>', { desc = 'Move to upper window' })
map('n', '<leader>wo', '<C-w><C-l>', { desc = 'Move to right window' })

-- Splits
map('n', '<leader>wv', '<C-w>v', { desc = 'Split [V]ertical' })
map('n', '<leader>wh', '<C-w>s', { desc = 'Split [H]orizontal' })
map('n', '<leader>w=', '<C-w>=', { desc = 'Split equal size' })
map('n', '<leader>wq', '<cmd>close<CR>', { desc = 'Split close' })

-- Buffers
map('n', '<leader>bn', '<cmd>bnext<CR>', { desc = '[B]uffer [N]ext' })
map('n', '<leader>bp', '<cmd>bprevious<CR>', { desc = '[B]uffer [P]revious' })
map('n', '<leader>bq', '<cmd>bdelete<CR>', { desc = '[B]uffer close' })

-- Misc
map('n', '<Esc>', '<cmd>nohlsearch<CR>', { desc = 'Clear search highlight' })
-- Highlight when yanking text
vim.api.nvim_create_autocmd('TextYankPost', {
  desc = 'Highlight when yanking (copying) text',
  group = vim.api.nvim_create_augroup('kickstart-highlight-yank', { clear = true }),
  callback = function() vim.highlight.on_yank() end,
})

-- Stay in indent mode after shifting in visual
map('v', '<', '<gv')
map('v', '>', '>gv')

-- Move selected lines up/down
map('v', 'E', ":m '>+1<CR>gv=gv")
map('v', 'I', ":m '<-2<CR>gv=gv")

-- Paste without overwriting clipboard
map('x', '<leader>p', '"_dP', { desc = 'Paste without losing clipboard' })

-- C
-- Save, compile with warnings+debug, then run
map('n', '<leader>cr', ':w<CR>:!gcc % -o %< -Wall -Wextra -g && ./%<<CR>', { desc = '[R]un current C file' })
-- Save and build only (just check for errors)
map('n', '<leader>cb', ':w<CR>:!gcc % -o %< -Wall -Wextra -g<CR>', { desc = '[B]uild current C file' })
