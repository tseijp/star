// @ts-check
// Note: type annotations allow type checking and IDEs autocompletion

const lightCodeTheme = require('prism-react-renderer/themes/github');
const darkCodeTheme = require('prism-react-renderer/themes/dracula');
const math = require('remark-math');
const katex = require('rehype-katex');

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: '🌠star',
  tagline: '🌠',
  url: 'https://tseijp.github.io',
  baseUrl: '/star/',
  onBrokenLinks: 'warn',
  onBrokenMarkdownLinks: 'warn',
  favicon: 'img/favicon.png',
  organizationName: 'tseijp',
  projectName: 'star',
  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          path: '../docs',
          routeBasePath: 'docs',
          // sidebarPath: require.resolve('./sidebars.js'),
          editUrl: 'https://github.com/tseijp/star/tree/main/docs/',
          remarkPlugins: [math],
          rehypePlugins: [katex],
        },
        // blog: {
        //   path: '../blog',
        //   routeBasePath: 'blog',
        //   showReadingTime: true,
        //   editUrl:
        //     'https://github.com/tseijp/star/tree/main/docs',
        // },
        theme: {
          // customCss: require.resolve('./src/css/custom.css'),
        },
      }),
    ],
  ],

  stylesheets: [
    {
      href: 'https://cdn.jsdelivr.net/npm/katex@0.13.24/dist/katex.min.css',
      type: 'text/css',
      integrity: 'sha384-odtC+0UGzzFL/6PNoE8rX/SPcQDXBJ+uRepguP4QkPCm2LBxH3FA3y+fKSiJ+AmM',
      crossorigin: 'anonymous',
    },
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      navbar: {
        title: 'star',
        logo: { alt: '🌠', src: 'img/favicon.png' },
        items: [
          { position: 'left', to: '/docs', label: 'Documents' },
          // { position: 'left', to: '/blog', label: 'Blog'},
          { position: 'right', label: 'GitHub', href: 'https://github.com/tseijp/star' },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          { title: 'Docs', items: [{ label: 'Tutorial',   to: '/docs'}] },
          { title: 'Community',
            items: [
              { label: 'Stack Overflow', href: 'https://stackoverflow.com/questions/tagged/star' },
              { label: 'Discord', href: 'https://bit.ly/3gBx5jL' },
              { label: 'Twitter', href: 'https://twitter.com/tseijp' },
            ],
          },
          { title: 'More',
            items: [
              { label: 'Documents', to: '/docs', },
              { label: 'GitHub', href: 'https://github.com/tseijp/star', },
            ],
          },
        ],
        copyright: `Copyright © ${new Date().getFullYear()} My Project, Inc. Built with Docusaurus.`,
      },
      prism: {
        theme: lightCodeTheme,
        darkTheme: darkCodeTheme,
      },
    }),
};

module.exports = config;
