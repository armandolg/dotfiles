-- return {
--   {
--     'bluz71/vim-moonfly-colors',
--     lazy = false,
--     priority = 1000,
--     init = function()
--       vim.cmd 'colorscheme moonfly'
--     end,
--   },
-- }
-- return {
--   {
--     'rebelot/kanagawa.nvim',
--     priority = 1000,
--     config = function()
--       ---@diagnostic disable-next-line: missing-fields
--       require('kanagawa').setup {
--         transparent = true,
--         colors = {
--           theme = {
--             all = {
--               ui = {
--                 bg_gutter = 'none',
--               },
--             },
--           },
--         },
--       }
--       vim.cmd.colorscheme 'kanagawa'
--     end,
--   },
-- }
return {
  {
    'catppuccin/nvim',
    name = 'catppuccin',
    lazy = false,
    priority = 1000,
    config = function()
      require('catppuccin').setup {
        transparent_background = true,
      }
      vim.cmd 'colorscheme catppuccin'
    end,
  },
}

-- vim: ts=2 sts=2 sw=2 et
