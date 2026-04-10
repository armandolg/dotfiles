return {
  {
    'folke/which-key.nvim',
    event = 'VeryLazy',
    opts = {
      delay = 400,
    },
    config = function(_, opts)
      local wk = require 'which-key'
      wk.setup(opts)

      wk.add {
        { '<leader>b', group = 'Buffers' },
        { '<leader>c', group = 'Code' },
        { '<leader>l', group = 'LSP' },
        { '<leader>s', group = 'Search' },
        { '<leader>w', group = 'Window Navigation' },
        { '<leader>g', group = 'Git' },
      }
    end,
  },
}
