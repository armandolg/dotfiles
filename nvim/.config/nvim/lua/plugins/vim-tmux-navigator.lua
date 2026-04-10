return {
  'christoomey/vim-tmux-navigator',
  init = function() vim.g.tmux_navigator_no_mappings = 1 end,
  config = function()
    local map = vim.keymap.set

    map('n', '<C-w>h', '<cmd>TmuxNavigateLeft<cr>')
    map('n', '<C-w>j', '<cmd>TmuxNavigateDown<cr>')
    map('n', '<C-w>k', '<cmd>TmuxNavigateUp<cr>')
    map('n', '<C-w>l', '<cmd>TmuxNavigateRight<cr>')

    map('n', '<leader>wn', '<cmd>TmuxNavigateLeft<cr>', { desc = 'Navigate Left' })
    map('n', '<leader>we', '<cmd>TmuxNavigateDown<cr>', { desc = 'Navigate Down' })
    map('n', '<leader>wi', '<cmd>TmuxNavigateUp<cr>', { desc = 'Navigate Up' })
    map('n', '<leader>wo', '<cmd>TmuxNavigateRight<cr>', { desc = 'Navigate Right' })
  end,
}
