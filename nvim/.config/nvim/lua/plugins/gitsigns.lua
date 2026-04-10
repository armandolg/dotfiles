return {
  {
    'lewis6991/gitsigns.nvim',
    event = 'BufReadPre',
    opts = {
      signs = {
        add = { text = '+' },
        change = { text = '~' },
        delete = { text = '_' },
        topdelete = { text = '‾' },
        changedelete = { text = '~' },
      },
      on_attach = function(bufnr)
        local gs = require 'gitsigns'
        local map = function(keys, func, desc) vim.keymap.set('n', keys, func, { buffer = bufnr, desc = 'Git: ' .. desc }) end

        map(']g', gs.next_hunk, 'Next [G]it hunk')
        map('[g', gs.prev_hunk, 'Previous [G]it hunk')

        map('<leader>gs', gs.stage_hunk, '[G]it [S]tage hunk')
        map('<leader>gr', gs.reset_hunk, '[G]it [R]eset hunk')
        map('<leader>gp', gs.preview_hunk, '[G]it [P]review hunk')
        map('<leader>gb', gs.blame_line, '[G]it [B]lame line')
        map('<leader>gd', gs.diffthis, '[G]it [D]iff')
      end,
    },
  },
}
