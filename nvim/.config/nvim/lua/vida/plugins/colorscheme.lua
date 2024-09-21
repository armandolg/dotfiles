return {
  {
    'sainnhe/gruvbox-material',
    priority = 1000,
    init = function()
      vim.g.gruvbox_material_background = 'hard'
      vim.g.gruvbox_material_better_performance = 1
      vim.cmd 'colorscheme gruvbox-material'
    end,
  },
}

-- vim: ts=2 sts=2 sw=2 et
