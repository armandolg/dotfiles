-- [[ Configure and install plugins ]]

require('lazy').setup({ { import = 'vida.plugins' } }, {
  checker = {
    enabled = true,
    notify = false,
  },
  change_detection = {
    notify = false,
  },
})

-- vim: ts=2 sts=2 sw=2 et
