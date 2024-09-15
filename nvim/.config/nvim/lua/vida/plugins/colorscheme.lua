return {
	-- "bluz71/vim-moonfly-colors",
	"sainnhe/gruvbox-material",
	priority = 1000,

	config = function()
		-- vim.cmd("colorscheme moonfly")
		vim.g.gruvbox_material_background = "hard"
		vim.g.gruvbox_material_better_performance = 1
		vim.cmd("colorscheme gruvbox-material")
	end,
}
