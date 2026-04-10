return {
  {
    'stevearc/conform.nvim',
    event = { 'BufWritePre' },
    opts = {
      formatters_by_ft = {
        c = { 'clang-format' },
        lua = { 'stylua' },
      },
      format_on_save = {
        timeout_ms = 500,
        lsp_format = 'fallback',
      },
    },
    keys = {
      {
        '<leader>f',
        function()
          require('conform').format {
            async = false,
            lsp_format = 'fallback',
          }
        end,
        desc = 'Code [F]ormat',
      },
    },
  },
}
