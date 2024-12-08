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
          name = 'vault',
          path = '~/vault',
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
      heading = {
        width = 'block',
        min_width = 50,
        border = true,
        backgrounds = {
          'RenderMarkdownH1Bg',
          'RenderMarkdownH2Bg',
          'RenderMarkdownH3Bg',
          'RenderMarkdownH4Bg',
          'RenderMarkdownH5Bg',
          'RenderMarkdownH6Bg',
        },
        foregrounds = {
          'RenderMarkdownH1',
          'RenderMarkdownH2',
          'RenderMarkdownH3',
          'RenderMarkdownH4',
          'RenderMarkdownH5',
          'RenderMarkdownH6',
        },
      },
      render_modes = { 'n', 'v', 'i', 'c' },
      code = {
        position = 'right',
        width = 'block',
        left_pad = 2,
        right_pad = 4,
      },
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
