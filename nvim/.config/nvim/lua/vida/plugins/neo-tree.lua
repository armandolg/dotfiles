return {
  'nvim-neo-tree/neo-tree.nvim',
  version = '*',
  dependencies = {
    'nvim-lua/plenary.nvim',
    'nvim-tree/nvim-web-devicons',
    'MunifTanjim/nui.nvim',
  },
  cmd = 'Neotree',
  keys = {
    { '<leader>e', ':Neotree reveal<CR>', desc = 'NeoTree reveal', silent = true },
  },
  init = function()
    vim.api.nvim_create_autocmd('BufEnter', {
      group = vim.api.nvim_create_augroup('NeoTreeInit', { clear = true }),
      callback = function()
        local f = vim.fn.expand '%:p'
        if f ~= '' and vim.fn.isdirectory(f) ~= 0 then
          pcall(function()
            vim.cmd('Neotree current dir=' .. vim.fn.fnameescape(f))
          end)
          vim.api.nvim_clear_autocmds { group = 'NeoTreeInit' }
        end
      end,
    })
  end,
  opts = {
    filesystem = {
      hijack_netrw_behavior = 'open_current',
      follow_current_file = {
        enabled = true,
      },
      filtered_items = {
        hide_dotfiles = false,
        hide_gitignored = false,
      },
      window = {
        position = 'right',
        width = 30,
        mappings = {
          ['<leader>e'] = 'close_window',
        },
      },
    },
  },
}

-- vim: ts=2 sts=2 sw=2 et
