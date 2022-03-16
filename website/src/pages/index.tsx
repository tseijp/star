import React from 'react';
import Layout from '@theme/Layout';
import Head from '@docusaurus/Head';

export default function App (props: any) {
  const { config: siteConfig } = props
  return (
    <Layout>
      <Head>
        <title>
          {siteConfig.title} {siteConfig.titleDelimiter} {siteConfig.tagline}
        </title>
        <div>
          <h1>{siteConfig.title}</h1>
          <p>{siteConfig.tagline}</p>
        </div>
      </Head>
      <main>
        <h1>
         STAR@TODO
        </h1>
      </main>
    </Layout>
  );
}
