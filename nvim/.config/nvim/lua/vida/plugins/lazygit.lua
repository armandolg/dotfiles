return {
  'kdheepak/lazygit.nvim',
  cmd = {
    'LazyGit',
    'LazyGitConfig',
    'LazyGitCurrentFile',
    'LazyGitFilter',
    'LazyGitFilterCurrentFile',
  },
  dependencies = {
    'nvim-lua/plenary.nvim',
  },
  keys = {
    { '<leader>hl', '<cmd>LazyGit<cr>', desc = 'Open [l]azy git' },
  },
}

-- vim: ts=2 sts=2 sw=2 et
