return {
  {
    'epwalsh/obsidian.nvim',
    version = '*',
    lazy = true,
    ft = 'markdown',
    dependencies = {
      'nvim-lua/plenary.nvim',
    },
    opts = {
      workspaces = {
        {
          name = 'Vault',
          path = '~/Documents/Vault/',
        },
      },
      ui = {
        enable = false,
        checkboxes = {
          [' '] = { char = '󰄱' },
          ['x'] = { char = '󰱒' },
          ['/'] = { char = '󰥔' },
        },
      },
      follow_url_func = function(url)
        vim.fn.jobstart { 'xdg-open', url }
      end,
    },
  },
  {
    'MeanderingProgrammer/render-markdown.nvim',
    dependencies = { 'nvim-treesitter/nvim-treesitter', 'nvim-tree/nvim-web-devicons' },
    opts = {
      checkbox = {
        enabled = true,
        position = 'inline',
        unchecked = {
          icon = '󰄱 ',
          highlight = 'RenderMarkdownUnchecked',
        },
        checked = {
          icon = '󰱒 ',
          highlight = 'RenderMarkdownChecked',
        },
        custom = {
          todo = { raw = '[/]', rendered = '󰥔 ', highlight = 'RenderMarkdownTodo' },
        },
      },
    },
  },
}

-- vim: ts=2 sts=2 sw=2 et
