return {
  {
    'akinsho/toggleterm.nvim',
    version = '*',
    config = function()
      require('toggleterm').setup {
        open_mapping = [[<c-t>]],
        direction = 'horizontal',
        shade_terminals = true,
      }
    end,
  },
}

-- vim: ts=2 sts=2 sw=2 et
