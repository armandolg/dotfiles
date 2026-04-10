return {
  {
    'mason-org/mason-lspconfig.nvim',
    dependencies = {
      { 'mason-org/mason.nvim', opts = { ui = { border = 'rounded' } } },
      { 'neovim/nvim-lspconfig' },
    },
    opts = {
      ensure_installed = { 'clangd' },
    },
  },

  -- clangd
  {
    'neovim/nvim-lspconfig',
    dependencies = { 'saghen/blink.cmp' },
    config = function()
      vim.lsp.config('clangd', {
        capabilities = require('blink.cmp').get_lsp_capabilities(),
        cmd = {
          'clangd',
          '--background-index',
          '--clang-tidy',
          '--header-insertion=never',
        },
        filetypes = { 'c', 'cpp' },
        root_markers = { 'compile_commands.json', 'compile_flags.txt', 'Makefile', '.git' },
      })

      vim.api.nvim_create_autocmd('LspAttach', {
        callback = function(event)
          local map = function(keys, func, desc)
            vim.keymap.set('n', keys, func, {
              buffer = event.buf,
              desc = 'LSP: ' .. desc,
            })
          end

          map('gd', vim.lsp.buf.definition, 'Go to [D]efinition')
          map('gD', vim.lsp.buf.declaration, 'Go to [D]eclaration')
          map('gr', vim.lsp.buf.references, 'Go to [R]eferences')

          map('K', vim.lsp.buf.hover, 'Hover docs')
          map('<leader>ld', vim.diagnostic.open_float, 'LSP [D]iagnostic')

          map('<leader>la', vim.lsp.buf.code_action, 'Code [A]ction')
          map('<leader>lr', vim.lsp.buf.rename, '[R]ename symbol')

          map('[d', vim.diagnostic.goto_prev, 'Previous diagnostic')
          map(']d', vim.diagnostic.goto_next, 'Next diagnostic')
        end,
      })

      vim.diagnostic.config {
        virtual_text = true,
        signs = true,
        underline = true,
        update_in_insert = false,
        float = { border = 'rounded' },
      }
    end,
  },
}
